#define WIN32_LEANAND_MEAN // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include <stdlib.h>		// malloc, free
#include <stdbool.h>	// bool

#include "../include/lib_func.h"

// safe_array を要素数nで初期化する
void initialize(safe_array* ar, int n)
{
	if (ar == NULL) return;// NULLチェック

	if (n <= 0)  // 非正の値が来たら、とりあえず空にする
	{
		ar->num = 0;
		ar->addr = NULL;
		return ;
	}

	ar->num = n;
	ar->addr = (int*)malloc(sizeof(int) * n);

	// 確保できなかったら要素数は0とする
	if (ar->addr == NULL)
	{
		ar->num = 0;
	}
}

// safe_array を解放する
void release(safe_array* ar)//OK?
{
	free(ar->addr);
	ar->addr = NULL;// 多重解放の防止
}

// safe_array の要素数を変更する(以前の値は要素が同じ範囲で残す)
void resize(safe_array* ar, int n)//OK
{
	int B_num = ar->num < n ? ar->num : n;
	int* B_array = (int*)malloc(sizeof(int) * B_num);
	B_array=ar->addr;

	initialize(ar, n);

	if (ar->addr != NULL)
	{
		for (int i = 0; i < B_num; i++)
			ar->addr[i] = B_array[i];
	}

	free(B_array);

	// ToOo:配列の要素数を変更しよう！(reallocは禁止)
}

// safe_array のindex番目の要素にvalを設定する
// index が確保されていない場所を指していたら返り値をfalseにする（設定出来たらtrue）
bool set(const safe_array* ar, int index, int val)//ok?
{
	// ToOo:配列の要素を変更しよう！
	if (ar->num>index  && index >= 0)
	{
		ar->addr[index] = val;
		return true;
	}
		return false;
}

// safe_array のindex番目の要素を取得する
// index が確保されていない場所を指していたら0を返す
int get(const safe_array* ar, int index)//OK?
{

	if (index<ar->num && index >= 0)
	{
		if (ar->addr[index] != NULL)
		{
			return  ar->addr[index];
		}
	}
	else return 0;
}
	// ToOo:要素を所得して、indexがおかしかったら0を返そう

// int_array の要素数を取得する
int size(const safe_array* ar)
{
	// ToOo: 配列の要素数を返そう
	return ar->num;
}