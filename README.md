Benchmark for PHP/Zephir/HHVM
=============================

## How to run?

By one command:

```bash
curl -sS https://raw.githubusercontent.com/ovr/php-zephir-hhvm-benchmark/master/benchmark.php | php
```

## Tests

* math
* methodCallEmpty
* methodCallBool
* arrayAppendInt
* arrayAppendString
* readClassConst
* readClassConstBySelf

## Simple output

```
| Test                 | Min                  | Max                  | Avg                  |
|----------------------|----------------------|----------------------|----------------------|
| math                 | 1.2821700572968      | 1.3130078315735      | 1.2895672798157      |
| methodCallEmpty      | 0.11392712593079     | 0.1202609539032      | 0.11500084400177     |
| methodCallBool       | 0.12116003036499     | 0.12568402290344     | 0.12210638523102     |
| arrayAppendInt       | 0.34773802757263     | 0.35477590560913     | 0.35250170230865     |
| arrayAppendString    | 0.35706996917725     | 0.36951684951782     | 0.36107654571533     |
| readClassConst       | 0.049347162246704    | 0.050116062164307    | 0.04967405796051     |
| readClassConstBySelf | 0.059558153152466    | 0.060733079910278    | 0.059996747970581    |

Max: 2.3833541870117
Min: 2.3381989002228
Score: 2k566
```