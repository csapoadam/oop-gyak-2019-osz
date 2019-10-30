#include "stdafx.h"
#include "climenu.h"
#include "climenuitem.h"

void CliMenu::addItem(CliMenuItem* clip) {
	menuItems.push_back(clip);
}

void CliMenu::display() {
	int itemCounter = 1;
	// use of undefined type 'CliMenuItem'
	// -> nincs definialva!
	for (CliMenuItem* clip : menuItems) {
		std::cout << itemCounter << ": " << clip->getItemText()
			<< std::endl;
		itemCounter++;
	}
}

CliMenu* CliMenu::selectItem(int choice) {
	// ket opcio: menuItems[x], menuItems.at(x)
	// de az .at() az bound check-et is tartalmaz
	try {
		CliMenuItem* mip = menuItems.at(choice - 1); // at az 0-tol szamoz
		mip->select();

		if (SubmenuCliMenuItem* scmip = dynamic_cast<SubmenuCliMenuItem*>(mip)) {
			return scmip->getSubMenu();
		}
		else {
			return this;
		}
	}
	catch (std::out_of_range e) {
		std::cout << "No such menu item, dodo!" << std::endl;
		return this;
	}
}