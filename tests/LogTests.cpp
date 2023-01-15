#include "Log.h"
#include "gtest/gtest.h"
namespace Inept::Logging::Tests {
    class LogTest : public ::testing::Test {
    protected:
        std::ostringstream* output_;
        LogTest() {
            output_ = new std::ostringstream();
            Inept::Logging::Log::Init(output_);
        }

        virtual ~LogTest() {
            // Clean up any resources used by the test
        }
    };

    TEST_F(LogTest, TestLogError) {
        Inept::Logging::Log::setOutput(output_);
        Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGERROR, "This is an error message.", false);
        std::string expected_output = "[ERROR] This is an error message.\n";
        EXPECT_EQ(output_->str(), expected_output);
    }

    TEST_F(LogTest, TestLogWarning) {
        Inept::Logging::Log::setOutput(output_);
        Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGWARNING, "This is a warning message.", false);
        std::string expected_output = "[WARNING] This is a warning message.\n";
        EXPECT_EQ(output_->str(), expected_output);
    }

    TEST_F(LogTest, TestLogInfo) {
        Inept::Logging::Log::setOutput(output_);
        Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGINFO, "This is an info message.", false);
        std::string expected_output = "[INFO] This is an info message.\n";
        EXPECT_EQ(output_->str(), expected_output);
    }

    TEST_F(LogTest, TestLogDebug) {
        Inept::Logging::Log::setOutput(output_);
        Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGDEBUG, "This is a debug message.", false);
        std::string expected_output = "[DEBUG] This is a debug message.\n";
        EXPECT_EQ(output_->str(), expected_output);
    }

    TEST_F(LogTest, TestLogTrace) {
        Inept::Logging::Log::setOutput(output_);
        Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGTRACE, "This is a trace message.", false);
        std::string expected_output = "[TRACE] This is a trace message.\n";
        EXPECT_EQ(output_->str(), expected_output);
    }

    TEST_F(LogTest, TestLogMessageEx) {
        Inept::Logging::Log::setOutput(output_);
        Inept::Logging::Log::logMessageEx("This is a custom message.", Inept::Logging::LogLevel::LOGINFO, Inept::Logging::LogColor::RED);
        std::string expected_output = "[INFO] This is a custom message.\n";
        EXPECT_EQ(output_->str(), expected_output);
    }
}