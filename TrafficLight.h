#pragma once

public ref class TrafficState abstract {
public:
	virtual System::String^ GetName() abstract;
	virtual void onEnter() abstract;
	virtual void onExit() abstract;
	virtual void onButtonPressed() abstract;
	virtual void onTimerTick() abstract;
	virtual int getElapsedSeconds() abstract; 
};

ref class TrafficLight;

public ref class RedLight : public TrafficState {
private:
	TrafficLight^ trafficLight_;
	int secondsElapsed_;
	int buttonPressedTime_;
	bool buttonPressed_;
public:
	RedLight(TrafficLight^ trafficLight);
	System::String^ GetName() override;
	void onEnter() override;
	void onExit() override;
	void onButtonPressed() override;
	void onTimerTick() override;
	int getElapsedSeconds() override; 
	property int secondsElapsed { int get() { return secondsElapsed_;} }
	property bool buttonPressed { bool get() { return buttonPressed_;} }

};

public ref class GreenLight : public TrafficState {
private:
	TrafficLight^ trafficLight_;
	int secondsElapsed_;
public:
	GreenLight(TrafficLight^ trafficLight);
	System::String^ GetName() override;
	void onEnter() override;
	void onExit() override;
	void onButtonPressed() override;
	void onTimerTick() override;
	int getElapsedSeconds() override;
	property int secondsElapsed { int get() { return secondsElapsed_; } }
};

public ref class TrafficLight {
private:
	TrafficState^ currentState_;
	System::Windows::Forms::Timer^ timer_;
	System::Windows::Forms::Panel^ redLight_;
	System::Windows::Forms::Panel^ greenLight_;
	System::Windows::Forms::Label^ labelElapsedTime_;
public:
	TrafficLight(System::Windows::Forms::Panel^ redLight
		       , System::Windows::Forms::Panel^ greenLight
			   , System::Windows::Forms::Label^ labelElapsedTime);
	void Start();
	void Stop();
	void ChangeState(TrafficState^ newState);
	void onButtonPressed();
	void onTimerTick(System::Object^ sender, System::EventArgs^ e);
	void setLight(bool isRed, bool isGreen);
};
