#pragma once

template <class T1, class T2>
struct SameType {
	static const bool value = false;
};

template <class T>
struct SameType<T,T> {
	static const bool value = true;
};