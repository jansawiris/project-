#pragma once
#include<string>
#include <map>
#include<list>
using namespace std;

typedef std::map<std::string, std::string> MessageMap;

// a basic window abstraction - demo purposes only
class WindowSettings
{
public:
	int x, y, w, h;
	string name;

	WindowSettings()
		: x(0), y(0), w(100), h(100), name("Untitled")
	{
	}

	WindowSettings(int x, int y, int w, int h, const string& name)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
		this->name = name;
	}
};

class ConnectionSettings
{
public:
	string ip;
	double timeout;
};

class AppSettings
{
public:
	string m_name;
	MessageMap m_messages;
	list<WindowSettings> m_windows;
	ConnectionSettings m_connection;

	AppSettings() {}

	void save(const char* pFilename) {

	}
	void load(const char* pFilename) {

	}

	// just to show how to do it
	void setDemoValues()
	{
		m_name = "MyApp";
		m_messages.clear();
		m_messages["Welcome"] = "Welcome to " + m_name;
		m_messages["Farewell"] = "Thank you for using " + m_name;
		m_windows.clear();
		m_windows.push_back(WindowSettings(15, 15, 400, 250, "Main"));
		m_connection.ip = "Unknown";
		m_connection.timeout = 123.456;
	}
};


	