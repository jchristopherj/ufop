#include <iostream>
#include <vector>
#include "Util.cpp"
#include "head.h"


bool is_possible(std::vector<int>valor, int candidato) {
	if (valor.size() == 0) {
		return true;
	}
	else {
		switch (valor.size())
		{
		case 1:
				if (valor[0] != candidato) {
					return false;
				}
				break;
		case 2:
			if (valor[0] >= candidato) {
				return false;
			}
			break;
		case 3:
			if (valor[2] != candidato) {
				return false;
			}
			break;
		default:
			break;
		}
		
	}
	return true;
	
}

bool dominios(std::vector<std::vector<int>>&d, std::vector<int>&candidatos, int aux) {
	
	if (candidatos.size() == 4) {
		printSequence(candidatos);
		return true;
	}
	else {
		
		for (int i = 0; i < d[aux].size(); i++) {			
				if (is_possible(candidatos, d[aux][i])) {
					candidatos.push_back(d[aux][i]);
					dominios(d, candidatos,aux++);
					candidatos.pop_back();					
				}
		}
	}
	return false;
}

int main() {
	std::vector<std::vector<int>>d= { {1,2,3}, {1,2,3}, {1,2,3,4}, {2,3,4} };	
	std::vector<int>candidatos({});	
	dominios(d,candidatos,0);
}
