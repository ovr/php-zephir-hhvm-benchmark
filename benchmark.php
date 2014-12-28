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


    public function simpleMethod()
    {
        return true;
    }

    public function methodCall($count)
    {
        for ($i=0; $i < $count; $i++) {
            $this->simpleMethod();
        }
    }

    public static function bench()
    {
        echo "Start Benchmark PHP " . PHP_VERSION . PHP_EOL;

        $count = 140000;

        $class = new Benchmark();
        $class->math($count);

        $class->methodCall($count);
    }
}

Benchmark::bench();