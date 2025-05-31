#include "Logger.h"

namespace Engine
{
	const char* logLevelLabels[3] = {
			"ERROR",
			"WARNING",
			"INFO"
	};


	Logger& Logger::Instance()
	{
		static Logger logger;
		return logger;
	}

	void Logger::setLogLevel(LogLevel logLevel)
	{
		m_logLevel = logLevel;
	}

	void Logger::info(const char* message)
	{
		if (m_logLevel == LOG_LEVEL_INFO)
		{
			log(message, LOG_LEVEL_INFO);
		}
	}

	void Logger::warn(const char* message)
	{
		if (m_logLevel >= LOG_LEVEL_WARN)
		{
			log(message, LOG_LEVEL_WARN);
		}
	}

	void Logger::error(const char* message)
	{
		if (m_logLevel >= LOG_LEVEL_ERROR)
		{
			log(message, LOG_LEVEL_ERROR);
		}
	}

	void Logger::log(const char* message, LogLevel messageLevel)
	{
		//Current time in system_clock::time_point format
		auto currentTime = std::chrono::system_clock::now();
		//Current time in time_t format
		auto currentTime_t = std::chrono::system_clock::to_time_t(currentTime);

		auto formattedTime = std::put_time(std::localtime(&currentTime_t), "%H:%M,%Ss");



		std::cout << "[" << logLevelLabels[messageLevel] << " @ " << formattedTime << "] " << message << '\n';
	}
}


