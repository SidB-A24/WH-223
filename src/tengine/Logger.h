#pragma once

#include <chrono>
#include <iostream>

namespace Engine
{
	enum LogLevel {
		LOG_LEVEL_INFO = 2,
		LOG_LEVEL_WARN = 1,
		LOG_LEVEL_ERROR = 0
	};


	class Logger {
	public:
		Logger(const Logger&) = delete;
		Logger operator = (const Logger&) = delete;

		static Logger& Instance();

		void setLogLevel(LogLevel logLevel);

		void info(const char* message);
		void warn(const char* message);
		void error(const char* message);

	private:
		Logger() {};

		LogLevel m_logLevel = LOG_LEVEL_INFO;

		void log(const char* message, LogLevel messageLevel);
	};
}