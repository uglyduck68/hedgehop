#pragma once

class ISimulator
{
public:
	ISimulator(){}
	virtual ~ISimulator() {}
	virtual void Init() = 0;
	virtual void Start() = 0;
	virtual void Stop() = 0;
	virtual void Resume() = 0;
	virtual void Pause() = 0;

};