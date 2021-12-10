#include "../Menus/Menu.h"
#include "../Menus/Tests.h"

int main() {
	Menu< char, double > *graphMenu = new Menu< char, double >();
	graphMenu -> principalManu();
	//Tests< char, double > *testMenu = new Tests< char, double >();
	//testMenu -> test();
	return 0;
}