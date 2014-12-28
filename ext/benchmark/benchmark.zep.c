
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"


/**
 * @author Patsura Dmitry <talk@dmtry.me>
 */
ZEPHIR_INIT_CLASS(Benchmark_Benchmark) {

	ZEPHIR_REGISTER_CLASS(Benchmark, Benchmark, benchmark, benchmark, benchmark_benchmark_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Benchmark_Benchmark, math) {

	HashTable *_6, *_13, *_20, *_27, *_34, *_41, *_48;
	HashPosition _5, _12, _19, _26, _33, _40, _47;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_8 = NULL, *_15 = NULL, *_22 = NULL, *_29 = NULL, *_36 = NULL, *_43 = NULL, *_50 = NULL;
	zval *_0, *_4 = NULL, *_9, *_11 = NULL, *_16, *_18 = NULL, *_23, *_25 = NULL, *_30, *_32 = NULL, *_37, *_39 = NULL, *_44, *_46 = NULL;
	zval *count, *i = NULL, _1 = zval_used_for_init, *_2 = NULL, **_7, *_10 = NULL, **_14, *_17 = NULL, **_21, *_24 = NULL, **_28, *_31 = NULL, **_35, *_38 = NULL, **_42, *_45 = NULL, **_49;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &count);



	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(&_2, "range", &_3, &_1, count);
	zephir_check_call_status();
	zephir_get_arrval(_4, _2);
	zephir_array_fast_append(_0, _4);
	zephir_is_iterable(_0, &_6, &_5, 0, 0, "benchmark/Benchmark.zep", 17);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(i, _7);
		ZEPHIR_CALL_FUNCTION(NULL, "abs", &_8, i);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_9);
	array_init_size(_9, 2);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(&_10, "range", &_3, &_1, count);
	zephir_check_call_status();
	zephir_get_arrval(_11, _10);
	zephir_array_fast_append(_9, _11);
	zephir_is_iterable(_9, &_13, &_12, 0, 0, "benchmark/Benchmark.zep", 21);
	for (
	  ; zephir_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
	  ; zephir_hash_move_forward_ex(_13, &_12)
	) {
		ZEPHIR_GET_HVALUE(i, _14);
		ZEPHIR_CALL_FUNCTION(NULL, "acos", &_15, i);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_16);
	array_init_size(_16, 2);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(&_17, "range", &_3, &_1, count);
	zephir_check_call_status();
	zephir_get_arrval(_18, _17);
	zephir_array_fast_append(_16, _18);
	zephir_is_iterable(_16, &_20, &_19, 0, 0, "benchmark/Benchmark.zep", 25);
	for (
	  ; zephir_hash_get_current_data_ex(_20, (void**) &_21, &_19) == SUCCESS
	  ; zephir_hash_move_forward_ex(_20, &_19)
	) {
		ZEPHIR_GET_HVALUE(i, _21);
		ZEPHIR_CALL_FUNCTION(NULL, "asin", &_22, i);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_23);
	array_init_size(_23, 2);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(&_24, "range", &_3, &_1, count);
	zephir_check_call_status();
	zephir_get_arrval(_25, _24);
	zephir_array_fast_append(_23, _25);
	zephir_is_iterable(_23, &_27, &_26, 0, 0, "benchmark/Benchmark.zep", 29);
	for (
	  ; zephir_hash_get_current_data_ex(_27, (void**) &_28, &_26) == SUCCESS
	  ; zephir_hash_move_forward_ex(_27, &_26)
	) {
		ZEPHIR_GET_HVALUE(i, _28);
		ZEPHIR_CALL_FUNCTION(NULL, "atan", &_29, i);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_30);
	array_init_size(_30, 2);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(&_31, "range", &_3, &_1, count);
	zephir_check_call_status();
	zephir_get_arrval(_32, _31);
	zephir_array_fast_append(_30, _32);
	zephir_is_iterable(_30, &_34, &_33, 0, 0, "benchmark/Benchmark.zep", 33);
	for (
	  ; zephir_hash_get_current_data_ex(_34, (void**) &_35, &_33) == SUCCESS
	  ; zephir_hash_move_forward_ex(_34, &_33)
	) {
		ZEPHIR_GET_HVALUE(i, _35);
		ZEPHIR_CALL_FUNCTION(NULL, "bindec", &_36, i);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_37);
	array_init_size(_37, 2);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(&_38, "range", &_3, &_1, count);
	zephir_check_call_status();
	zephir_get_arrval(_39, _38);
	zephir_array_fast_append(_37, _39);
	zephir_is_iterable(_37, &_41, &_40, 0, 0, "benchmark/Benchmark.zep", 37);
	for (
	  ; zephir_hash_get_current_data_ex(_41, (void**) &_42, &_40) == SUCCESS
	  ; zephir_hash_move_forward_ex(_41, &_40)
	) {
		ZEPHIR_GET_HVALUE(i, _42);
		ZEPHIR_CALL_FUNCTION(NULL, "floor", &_43, i);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_44);
	array_init_size(_44, 2);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(&_45, "range", &_3, &_1, count);
	zephir_check_call_status();
	zephir_get_arrval(_46, _45);
	zephir_array_fast_append(_44, _46);
	zephir_is_iterable(_44, &_48, &_47, 0, 0, "benchmark/Benchmark.zep", 40);
	for (
	  ; zephir_hash_get_current_data_ex(_48, (void**) &_49, &_47) == SUCCESS
	  ; zephir_hash_move_forward_ex(_48, &_47)
	) {
		ZEPHIR_GET_HVALUE(i, _49);
		ZEPHIR_CALL_FUNCTION(NULL, "exp", &_50, i);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Benchmark_Benchmark, bench) {

	int count = 14000000, ZEPHIR_LAST_CALL_STATUS;
	zval *tmp, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(tmp);
	object_init_ex(tmp, benchmark_benchmark_ce);
	if (zephir_has_constructor(tmp TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, tmp, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, count);
	ZEPHIR_CALL_METHOD(NULL, tmp, "math", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

