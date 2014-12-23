<?php
/**
 * @author Patsura Dmitry <talk@dmtry.me>
 */

class Benchmark {
    public function math(var count)
    {
        var i;

        for (i = 0; i < count; i++) {
            abs(i);
        }

        for (i = 0; i < count; i++) {
            acos(i);
        }

        for (i = 0; i < count; i++) {
            asin(i);
        }

        for (i = 0; i < count; i++) {
            atan(i);
        }

        for (i = 0; i < count; i++) {
            bindec(i);
        }

        for (i = 0; i < count; i++) {
            floor(i);
        }

        for (i = 0; i < count; i++) {
            exp(i);
        }
    }

    public static function bench()
    {
        var count = 14000000;

        var class = new Benchmark();
        class->math(count);
    }
}