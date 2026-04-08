#include "TrafficLight.h"

RedLight::RedLight(TrafficLight^ trafficLight)
	: trafficLight_(trafficLight), secondsElapsed_(0), buttonPressedTime_(0), buttonPressed_(false)
{}

System::String^ RedLight::GetName() {
	return L"Red";
}

void RedLight::onEnter() {
	secondsElapsed_ = 0;
	buttonPressed_ = false;
	trafficLight_->setLight(true, false);
}

void RedLight::onExit() {}

void RedLight::onButtonPressed() {
	if (secondsElapsed_ >= 10) {
		buttonPressed_ = true;
		buttonPressedTime_ = secondsElapsed_;
	}
}

void RedLight::onTimerTick() {
	++secondsElapsed_;
	if (buttonPressed_ && secondsElapsed_ >= buttonPressedTime_ + 5)
		trafficLight_->ChangeState(gcnew GreenLight(trafficLight_));

}

int RedLight::getElapsedSeconds()
{
	return secondsElapsed_;
}

GreenLight::GreenLight(TrafficLight^ trafficLight)
	: trafficLight_(trafficLight), secondsElapsed_(0)
{}

System::String^ GreenLight::GetName() {
	return L"Green";
}

void GreenLight::onEnter() {
	secondsElapsed_ = 0;
	trafficLight_->setLight(false, true);
}

void GreenLight::onExit() {}

void GreenLight::onButtonPressed() {}

void GreenLight::onTimerTick() {
	++secondsElapsed_;
	if (secondsElapsed_ >= 10)
		trafficLight_->ChangeState(gcnew RedLight(trafficLight_));
}

int GreenLight::getElapsedSeconds()
{
	return secondsElapsed_;
}

TrafficLight::TrafficLight(System::Windows::Forms::Panel^ redLight
	                     , System::Windows::Forms::Panel^ greenLight
						, System::Windows::Forms::Label^ labelElapsedTime)
	: redLight_(redLight)
	, greenLight_(greenLight)
	, timer_(gcnew System::Windows::Forms::Timer()) 
	, labelElapsedTime_(labelElapsedTime) {
	timer_->Interval = 1000;
	timer_->Tick += gcnew System::EventHandler(this, &TrafficLight::onTimerTick);
	currentState_ = gcnew RedLight(this);
}

void TrafficLight::Start() {
	currentState_->onEnter();
	timer_->Start();
}

void TrafficLight::Stop() {
	timer_->Stop();
}

void TrafficLight::ChangeState(TrafficState^ newState) {
	currentState_->onExit();
	currentState_ = newState;
	currentState_->onEnter();
}


void TrafficLight::onButtonPressed() {
	currentState_->onButtonPressed();
}

void TrafficLight::onTimerTick(System::Object^ sender, System::EventArgs^ e) {
	currentState_->onTimerTick();
	labelElapsedTime_->Text = System::Convert::ToString(currentState_->getElapsedSeconds());
}

void TrafficLight::setLight(bool isRed, bool isGreen) {
	redLight_->BackColor = isRed ? 
		                      System::Drawing::Color::Red 
		                    : System::Drawing::Color::DarkRed;
	greenLight_->BackColor = isGreen ?
							  System::Drawing::Color::LawnGreen
							: System::Drawing::Color::DarkSeaGreen;
	redLight_->Refresh();
	greenLight_->Refresh();
}




