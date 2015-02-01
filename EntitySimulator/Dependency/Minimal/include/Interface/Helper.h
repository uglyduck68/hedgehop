#pragma once
#include <memory>
#include <functional>
class ICommandInterface;
bool AddCommand(const size_t& Hash,ICommandInterface* Command);
ICommandInterface* GetCommand(const size_t& Hash);
void AddData(int flag,void* data,unsigned short len,std::function<void(void*)> func);
void AddTask(std::function<void()> work, int type);