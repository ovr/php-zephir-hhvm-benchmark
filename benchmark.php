<?php
/**
 * @author Patsura Dmitry <talk@dmtry.me>
 */

namespace Bench;

class Table
{
    protected $headers;

    protected $rows;

    protected $maxWidth = 8;

    public function setHeaders(array $headers)
    {
        $this->headers = $headers;

        foreach ($headers as $header) {
            $this->maxWidth = max(strlen($header), $this->maxWidth);
        }
    }

    public function addRow(array $row)
    {
        $this->rows[] = $row;

        foreach ($row as $header) {
            $this->maxWidth = max(strlen($header), $this->maxWidth);
        }
    }

    public function printTable()
    {
        echo str_repeat('-', (($this->maxWidth+3)*count($this->headers))+1) . PHP_EOL;

        echo '|';

        foreach ($this->headers as $header) {
            echo ' ' . $header . (str_repeat(' ', $this->maxWidth-strlen($header))) . ' |';
        }

        echo PHP_EOL;
        echo str_repeat('-', (($this->maxWidth+3)*count($this->headers))+1) . PHP_EOL;

        foreach ($this->rows as $row) {
            echo '|';

            foreach ($row as $header) {
                echo ' ' . $header . (str_repeat(' ', $this->maxWidth-strlen($header))) . ' |';
            }

            echo PHP_EOL;
            echo str_repeat('-', (($this->maxWidth+3)*count($this->headers))+1) . PHP_EOL;
        }
    }
}

class Benchmark
{
    const SIMPLE_BOOL = true;

    public function math($count)
    {
        for ($i=0; $i < $count; $i++) {
            abs($i);
        }

        for ($i=0; $i < $count; $i++) {
            acos($i);
        }

        for ($i=0; $i < $count; $i++) {
            asin($i);
        }

        for ($i=0; $i < $count; $i++) {
            atan($i);
        }

        for ($i=0; $i < $count; $i++) {
            bindec($i);
        }

        for ($i=0; $i < $count; $i++) {
            floor($i);
        }

        for ($i=0; $i < $count; $i++) {
            exp($i);
        }
    }


    public function simpleMethodEmpty()
    {
    }

    public function simpleMethodBool()
    {
        return true;
    }

    public function methodCallEmpty($count)
    {
        for ($i=0; $i < $count; $i++) {
            $this->simpleMethodEmpty();
        }
    }

    public function methodCallBool($count)
    {
        for ($i=0; $i < $count; $i++) {
            $this->simpleMethodBool();
        }
    }

    public function arrayAppendInt($count)
    {
        $tmp = array();

        for ($i=0; $i < $count; $i++) {
            $tmp[] = 1;
        }
    }

    public function arrayAppendString($count)
    {
        $tmp = array();

        for ($i=0; $i < $count; $i++) {
            $tmp[] = "";
        }
    }

    public function readClassConstBySelf($count)
    {
        for ($i=0; $i < $count; $i++) {
            $tmp = self::SIMPLE_BOOL;
        }
    }

    public function readClassConst($count)
    {
        for ($i=0; $i < $count; $i++) {
            $tmp = Benchmark::SIMPLE_BOOL;
        }
    }

    static protected $statistics;

    public static function benchCall($class, $method, $count)
    {
        $startTime = microtime(true);
        $class->{$method}($count);

        $elapsed = microtime(true) - $startTime;
        self::$statistics[$method] = $elapsed;

        echo ucfirst($method) . ": ($elapsed) sec." . PHP_EOL;

        return $elapsed;
    }

    public static function bench()
    {
        echo "Benchmark PHP-" . PHP_VERSION . PHP_EOL;
        echo "OS: " . PHP_OS . PHP_EOL;
        echo "Info: " . php_uname('a') . PHP_EOL;

        echo str_repeat('=', 40) . PHP_EOL;

        $max = -10;
        $min = 10;

        $count = 1400000;
        $rounds = 10;

        $class = new Benchmark();

        $allStatistics = array();

        for ($i = 0; $i < $rounds; $i++) {
            self::$statistics = [];
            $total = 0;

            echo "Round " . ($i+1) . "...." . PHP_EOL;
            $total += Benchmark::benchCall($class, 'math', $count);

            $total += Benchmark::benchCall($class, 'methodCallEmpty', $count);
            $total += Benchmark::benchCall($class, 'methodCallBool', $count);

            $total += Benchmark::benchCall($class, 'arrayAppendInt', $count);
            $total += Benchmark::benchCall($class, 'arrayAppendString', $count);

            $total += Benchmark::benchCall($class, 'readClassConst', $count);
            $total += Benchmark::benchCall($class, 'readClassConstBySelf', $count);

            echo "end" . PHP_EOL;
            echo PHP_EOL;

            $min = min($min, $total);
            $max = max($max, $total);

            $allStatistics[] = self::$statistics;
        }

        $table = new Table();
        $table->setHeaders(array('Test', 'Min', 'Max', 'Avg'));

        foreach ($allStatistics[0] as $key => $row) {
            $minRow = 10;
            $maxRow = -10;
            $avgRow = 0;

            for ($i = 0; $i < $rounds; $i++) {
                $value = $allStatistics[$i][$key];

                $minRow = min($minRow, $value);
                $maxRow = max($maxRow, $value);
                $avgRow += $value;
            }

            $table->addRow([$key, $minRow, $maxRow, $avgRow/$rounds]);
        }

        /**
         * 0.1 - 60 000
         * $min -
         */

        $perfect = 0.1;
        $perfectScore = 60000;

        echo str_repeat('=', 40) . PHP_EOL;

        $table->printTable();

        echo "Max: " . $max . PHP_EOL;
        echo "Min: " . $min . PHP_EOL;

        $score = ($perfect/$min)*$perfectScore;
        echo "Score: " . number_format($score, 0, ' ', 'k') . PHP_EOL;
    }
}

Benchmark::bench();