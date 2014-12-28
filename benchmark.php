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

        $count = 1400000;
        $class = new Benchmark();

        Benchmark::benchCall($class, 'math', $count);
        Benchmark::benchCall($class, 'methodCallEmpty', $count);
        Benchmark::benchCall($class, 'methodCallBool', $count);
        Benchmark::benchCall($class, 'arrayAppendInt', $count);
        Benchmark::benchCall($class, 'arrayAppendString', $count);

        echo str_repeat('-', 40) . PHP_EOL;
    }
}

Benchmark::bench();