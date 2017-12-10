#pragma once

struct Greater { 
	bool operator()(int a, int b) const { return b < a; }
};