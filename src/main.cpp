#include "../Menus/Menu.h"

int main() {
	Menu< char, int > *graphMenu = new Menu< char, int >();
	graphMenu -> principalManu();
	return 0;
}