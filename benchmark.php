<?php
/**
 * @author Patsura Dmitry <talk@dmtry.me>
 */

class Benchmark {
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

    public static function benchCall($class, $method, $count)
    {
        $startTime = microtime(true);
        $class->{$method}($count);

        $elapsed = microtime(true) - $startTime;
        echo ucfirst($method) . ": ($elapsed) sec." . PHP_EOL;

        return $elapsed;
    }

    public static function bench()
    {
        echo "Start Benchmark PHP " . PHP_VERSION . PHP_EOL;
        echo str_repeat('-', 40) . PHP_EOL;

        $max = -10;
        $min = 10;

        $count = 1400000;
        $rounds = 15;

        $class = new Benchmark();

        for ($i = 0; $i < $rounds; $i++) {
            $total = 0;

            echo "Round " . ($i+1) . "...." . PHP_EOL;
            $total += Benchmark::benchCall($class, 'math', $count);
            $total += Benchmark::benchCall($class, 'methodCallEmpty', $count);
            $total += Benchmark::benchCall($class, 'methodCallBool', $count);
            $total += Benchmark::benchCall($class, 'arrayAppendInt', $count);
            $total += Benchmark::benchCall($class, 'arrayAppendString', $count);
            echo "end" . PHP_EOL;
            echo PHP_EOL;

            $min = min($min, $total);
            $max = max($max, $total);
        }


        /**
         * 0.1 - 60 000
         * $min -
         */

        $perfect = 0.1;
        $perfectScore = 60000;

        echo str_repeat('-', 40) . PHP_EOL;
        echo "Max: " . $max . PHP_EOL;
        echo "Min: " . $min . PHP_EOL;

        $score = ($perfect/$min)*$perfectScore;
        echo "Score: " . number_format($score, 0, ' ', 'k') . PHP_EOL;
    }
}

Benchmark::bench();