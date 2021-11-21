#include "../Menus/Menu.h"

int main() {
	Menu< char, double > *graphMenu = new Menu< char, double >();
	graphMenu -> principalManu();
	return 0;
}