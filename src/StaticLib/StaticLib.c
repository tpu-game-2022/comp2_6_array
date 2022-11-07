#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include <stdlib.h>		// malloc, free
#include <stdbool.h>	// bool

#include "../include/lib_func.h"

// safe_array を要素数nで初期化する
void initialize(safe_array* ar, int n)
{
	if (ar == NULL) return;// NULLチェック

	if (n <= 0) { // 非正の値が来たら、とりあえず空にする
		ar->num = 0;
		ar->addr = NULL;
		return;
	}

	ar->num = n;
	ar->addr = (int*)malloc(sizeof(int) * n);

	// 確保できなかったら要素数は0とする
	if (ar->addr == NULL) ar->num = 0;
}

// safe_array を解放する
void release(safe_array* ar)
{
	free(ar->addr);
	ar->addr = NULL;// 多重解放の防止
}

void coppyArray(safe_array* ar, safe_array* coppy, int n)
{
	for (int i = 0; i < n; i++)
	{
		coppy->addr[i] = ar->addr[i];
	}
}

// safe_array の要素数を変更する(以前の値は要素が同じ範囲で残す)
void resize(safe_array* ar, int n)
{
	// ToOo:配列の要素数を変更しよう！(reallocは禁止)
	safe_array safe_ar;
	initialize(&safe_ar, n);

	int element_count;
	if (n > ar->num)
		element_count = ar->num;
	else
		element_count = n;

	coppyArray(&*ar, &safe_ar, element_count);
	release(&*ar);
	initialize(&*ar,n);

	coppyArray(&safe_ar, &*ar, n);

	release(&safe_ar);
}

// safe_array のindex番目の要素にvalを設定する
// index が確保されていない場所を指していたら返り値をfalseにする（設定出来たらtrue）
bool set(const safe_array* ar, int index, int val)
{
	if (index<0 || index>ar->num - 1)
		return false;

	else
	{
        ar->addr[index] = val;
	    return true;
	}
		
	
	// ToOo:配列の要素を変更しよう！
	
}

// safe_array のindex番目の要素を取得する
// index が確保されていない場所を指していたら0を返す
int get(const safe_array* ar, int index)
{
	if (index<0 || index>ar->num - 1)
		return 0;

	else
		return ar->addr[index];
	// ToOo:要素を所得して、indexがおかしかったら0を返そ
}

// int_array の要素数を取得する
int size(const safe_array* ar)
{
	// ToOo: 配列の要素数を返そう
	return ar->num;
}