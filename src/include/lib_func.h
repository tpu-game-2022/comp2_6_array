#pragma once // インクルードガード

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif


typedef struct
{
	int num;
	int* addr;
} safe_array;

// safe_array を要素数nで初期化する
void initialize(safe_array* ar, int n);

// safe_array を解放する
void release(safe_array *ar);

// safe_array の要素数を変更する(以前の値は要素が同じ範囲で残す)
void resize(safe_array* ar, int n);

// safe_array のindex番目の要素にvalを設定する
// index が確保されていない場所を指していたら返り値をfalseにする（設定出来たらtrue）
bool set(const safe_array* ar, int index, int val);

// safe_array のindex番目の要素を取得する
// index が確保されていない場所を指していたら0を返す
int get(const safe_array* ar, int index);

// int_array の要素数を取得する
int size(const safe_array* ar);



// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
