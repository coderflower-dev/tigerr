#pragma once
/*
	TiGErr C++ Error logging library
	Version 1.0.0
	Copyright 2025 Timur Gabdrakhmanov. MIT License.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

namespace tg {

	enum Severity {
		NOTICE, // Used for simple logging
		ALERT, // An error that is not good to see but not mission critical
		FAILURE, // A critical failure
	};

	enum LogOutput {
		CONSOLE, // Prints out the the standard application console
		FILE, // Logs to file
		CONSOLE_AND_FILE, // Both prints and logs
	};

	/// <summary>
	/// Advanced error logging function
	/// </summary>
	/// <param name="errorLabel"> - Error title or error code </param>
	/// <param name="errorDetails"> - More in-depth information about error </param>
	/// <param name="errorSeverity"> - Criticality of the error </param>
	/// <param name="asciiColor"> - Toggle for color usage when printing to console </param>
	/// <param name="outout"> - Enum controlling the output of the error </param>
	/// <param name="logPath"> - Path for Log file, only used when output is set to FILE or CONSOLE_AND_FILE</param>
	inline void LogError(std::string errorLabel, std::string errorDetails, Severity errorSeverity, bool asciiColor, LogOutput output, std::string logPath = "") {
		
		std::string message = "";
		std::string prefix = "";
		std::string colorCode = "";
		std::string resetCode = "\033[0m";

		switch (errorSeverity) {
			case NOTICE: prefix = "NOTICE: "; colorCode = resetCode; break;
			case ALERT: prefix = "ALERT: ";  colorCode = "\033[33m"; break;
			case FAILURE: prefix = "FAILURE: "; colorCode = "\033[1;31m"; break;
			default: std::cout << "LogError Severity Error! Contact Developer with Code 100!\n"; break;
		}

		message = (prefix + errorLabel + ": " + errorDetails + "\n");
		
		if (output == FILE || output == CONSOLE_AND_FILE) {
			std::filesystem::path fsPath(logPath);
			if (std::filesystem::exists(fsPath)) {
				std::ofstream file(logPath);
				if (!file.is_open()) {
					std::cout << "LogError Cannot Open Log File! \"" << logPath << "\". Contact Developer with Code 201!\n";
				}
				file << message;
			}
			else {
				std::cout << "LogError Cannot Find Log File! \"" << logPath << "\". Contact Developer with Code 200!\n";
			}
		}

		if (asciiColor)
			message = colorCode + message + resetCode;

		if (output == CONSOLE || output == CONSOLE_AND_FILE) {
			std::cout << message;
		}
		

	}
}

/*
	Error Code Lookup:
	Code 100 - Invalid Error Severity, check "errorSeverity" parameter and make sure its either NOTICE, ALERT, or FAILURE
	Code 200 - Cannot find specified Log file, check "logPath"
	Code 201 - For some reason couldn't open your desired "logPath", I have no idea how to fix this
*/
