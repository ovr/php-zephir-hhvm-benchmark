
extern zend_class_entry *benchmark_benchmark_ce;

ZEPHIR_INIT_CLASS(Benchmark_Benchmark);

PHP_METHOD(Benchmark_Benchmark, math);
PHP_METHOD(Benchmark_Benchmark, bench);

ZEND_BEGIN_ARG_INFO_EX(arginfo_benchmark_benchmark_math, 0, 0, 1)
	ZEND_ARG_INFO(0, count)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(benchmark_benchmark_method_entry) {
	PHP_ME(Benchmark_Benchmark, math, arginfo_benchmark_benchmark_math, ZEND_ACC_PUBLIC)
	PHP_ME(Benchmark_Benchmark, bench, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
