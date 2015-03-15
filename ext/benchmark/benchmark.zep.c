
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"


/**
 * @author Patsura Dmitry <talk@dmtry.me>
 */
ZEPHIR_INIT_CLASS(Benchmark_Benchmark) {

	ZEPHIR_REGISTER_CLASS(Benchmark, Benchmark, benchmark, benchmark, benchmark_benchmark_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Benchmark_Benchmark, math) {

	zend_bool _0, _3, _6, _9, _12, _15;
	int i, _1, _4, _7, _10, _13, _16;
	zval *count, *_2 = NULL, *_5 = NULL, *_8 = NULL, *_11 = NULL, *_14 = NULL, *_17 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &count);



	ZEPHIR_CPY_WRT(_2, count);
	_1 = 1;
	_0 = 0;
	if (ZEPHIR_GE_LONG(_2, _1)) {
		while (1) {
			if (_0) {
				_1++;
				if (!(ZEPHIR_GE_LONG(_2, _1))) {
					break;
				}
			} else {
				_0 = 1;
			}
			i = _1;
			i = abs(i);
			i;
		}
	}
	ZEPHIR_CPY_WRT(_5, count);
	_4 = 1;
	_3 = 0;
	if (ZEPHIR_GE_LONG(_5, _4)) {
		while (1) {
			if (_3) {
				_4++;
				if (!(ZEPHIR_GE_LONG(_5, _4))) {
					break;
				}
			} else {
				_3 = 1;
			}
			i = _4;
			i = acos(i);
			i;
		}
	}
	ZEPHIR_CPY_WRT(_8, count);
	_7 = 1;
	_6 = 0;
	if (ZEPHIR_GE_LONG(_8, _7)) {
		while (1) {
			if (_6) {
				_7++;
				if (!(ZEPHIR_GE_LONG(_8, _7))) {
					break;
				}
			} else {
				_6 = 1;
			}
			i = _7;
			i = asin(i);
			i;
		}
	}
	ZEPHIR_CPY_WRT(_11, count);
	_10 = 1;
	_9 = 0;
	if (ZEPHIR_GE_LONG(_11, _10)) {
		while (1) {
			if (_9) {
				_10++;
				if (!(ZEPHIR_GE_LONG(_11, _10))) {
					break;
				}
			} else {
				_9 = 1;
			}
			i = _10;
			i = atan(i);
			i;
		}
	}
	ZEPHIR_CPY_WRT(_14, count);
	_13 = 1;
	_12 = 0;
	if (ZEPHIR_GE_LONG(_14, _13)) {
		while (1) {
			if (_12) {
				_13++;
				if (!(ZEPHIR_GE_LONG(_14, _13))) {
					break;
				}
			} else {
				_12 = 1;
			}
			i = _13;
			i = floor(i);
			i;
		}
	}
	ZEPHIR_CPY_WRT(_17, count);
	_16 = 1;
	_15 = 0;
	if (ZEPHIR_GE_LONG(_17, _16)) {
		while (1) {
			if (_15) {
				_16++;
				if (!(ZEPHIR_GE_LONG(_17, _16))) {
					break;
				}
			} else {
				_15 = 1;
			}
			i = _16;
			i = exp(i);
			i;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Benchmark_Benchmark, bench) {

	int ZEPHIR_LAST_CALL_STATUS, count = 14000000;
	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL;
	zval *_0, *_1, *_2, *_3, *_4, *_5, _6, *_7 = NULL, *_9, *_10, *tmp, *_11;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_VERSION");
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVV(_2, "Benchmark PHP-", _0, _1);
	zend_print_zval(_2, 0);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_GET_CONSTANT(_3, "PHP_OS");
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_GET_CONSTANT(_4, "PHP_EOL");
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SVV(_5, "OS: ", _3, _4);
	zend_print_zval(_5, 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 'a');
	ZEPHIR_CALL_FUNCTION(&_7, "php_uname", &_8, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_GET_CONSTANT(_9, "PHP_EOL");
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_SVV(_10, "Info: ", _7, _9);
	zend_print_zval(_10, 0);
	ZEPHIR_INIT_VAR(tmp);
	object_init_ex(tmp, benchmark_benchmark_ce);
	if (zephir_has_constructor(tmp TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, tmp, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_11);
	ZVAL_LONG(_11, count);
	ZEPHIR_CALL_METHOD(NULL, tmp, "math", NULL, _11);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

