#include <iostream>
using namespace std;

class IButton {
public:
	virtual void draw()=0;
	virtual void on_click()=0;
};

class ILabel {
public:
	virtual void draw() = 0;
};

class IGUIFactory {
public:
	virtual IButton* CreateButton() = 0;
	virtual ILabel* CreateLabel() = 0;
};
class WinButton : public IButton {
public:
	void draw()
	{
		cout<<"Drawing Windows Button"<<endl;
	}
	void on_click()
	{
		cout<<"Clicked on Windows Button"<<endl;
	}
};

class WinLabel: public ILabel {
public:
	void draw()
	{
		cout<<"Drawing Windows Label"<<endl;
	}
};

class UnixButton : public IButton {
public:
	void draw()
	{
		cout<<"Drawing Unix Button"<<endl;
	}
	void on_click()
	{
		cout<<"Clicked on Unix Button"<<endl;
	}
};

class UnixLabel: public ILabel {
public:
	void draw()
	{
		cout<<"Drawing Unix Label"<<endl;
	}
};

class WinGuiFactory: public IGUIFactory {
public:
	WinGuiFactory(){cout<<"WinGuiFactory"<<endl;}
	virtual IButton* CreateButton()
	{
		return new WinButton();
	}
	virtual ILabel* CreateLabel()
	{
		return new WinLabel();
	}
};

class UnixGuiFactory: public IGUIFactory {
public:
	UnixGuiFactory(){cout<<"UnixGuiFactory"<<endl;}
	virtual IButton* CreateButton()
	{
		return new UnixButton();
	}
	virtual ILabel* CreateLabel()
	{
		return new UnixLabel();
	}
};

int main()
{
	IGUIFactory *WinGuiFactory_ptr;
	WinGuiFactory_ptr = new WinGuiFactory();
	IGUIFactory *UnixGuiFactory_ptr = new UnixGuiFactory();

	IButton *WButton = WinGuiFactory_ptr->CreateButton();
	ILabel *WLabel = WinGuiFactory_ptr->CreateLabel();

	WButton->draw();
	WButton->on_click();
	WLabel->draw();

	IButton *UButton = UnixGuiFactory_ptr->CreateButton();
	ILabel *ULabel = UnixGuiFactory_ptr->CreateLabel();

	UButton->draw();
	UButton->on_click();
	ULabel->draw();

	return 0;
}