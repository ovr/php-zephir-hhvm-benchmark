/**
 * @author Patsura Dmitry <talk@dmtry.me>
 */

namespace Benchmark;

class Benchmark
{
    public function math(var count)
    {
        var i;

        for i in [1...count] {
            abs(i);
        }

        for i in [1...count] {
            acos(i);
        }

        for i in [1...count] {
            asin(i);
        }

        for i in [1...count] {
            atan(i);
        }

        for i in [1...count] {
            bindec(i);
        }

        for i in [1...count] {
            floor(i);
        }

        for i in [1...count] {
            exp(i);
        }
    }

    public static function bench()
    {
        echo "Benchmark PHP-" . PHP_VERSION . PHP_EOL;
        echo "OS: " . PHP_OS . PHP_EOL;
        echo "Info: " . php_uname('a') . PHP_EOL;

        var tmp;
        var count = 14000000;

        let tmp = new Benchmark();
        tmp->math(count);
    }
}