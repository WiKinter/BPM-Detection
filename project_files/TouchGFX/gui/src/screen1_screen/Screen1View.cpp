#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
    setNewBPMValue(0);
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
void Screen1View::setNewBPMValue(int val){
	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d.%d", val / 10, val % 10);
	textArea1.invalidate();
}
void Screen1View::handleTickEvent()
{
    setNewBPMValue(bpmValue);
}
