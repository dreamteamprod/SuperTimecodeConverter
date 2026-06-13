cmake_minimum_required(VERSION 3.22)
project(SuperTimecodeConverter VERSION 1.9.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../JUCE ${CMAKE_BINARY_DIR}/JUCE)

juce_add_gui_app(SuperTimecodeConverter
    PRODUCT_NAME "Super Timecode Converter"
    COMPANY_NAME "Fiverecords"
    VERSION "1.9.9"
    HARDENED_RUNTIME_ENABLED TRUE
    HARDENED_RUNTIME_OPTIONS com.apple.security.device.audio-input
    MICROPHONE_PERMISSION_ENABLED TRUE
    MICROPHONE_PERMISSION_TEXT "STC needs access to your audio interface for LTC input"
)

juce_generate_juce_header(SuperTimecodeConverter)

target_sources(SuperTimecodeConverter PRIVATE
    Main.cpp
    MainComponent.cpp
    sqlite3.c
    btt_build.cpp
)

target_compile_definitions(SuperTimecodeConverter PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:SuperTimecodeConverter,JUCE_PRODUCT_NAME>"
    JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:SuperTimecodeConverter,JUCE_VERSION>"
    SQLITE_THREADSAFE=1
    $<$<PLATFORM_ID:Windows>:NOMINMAX>
)

target_link_libraries(SuperTimecodeConverter PRIVATE
    juce::juce_audio_basics
    juce::juce_audio_devices
    juce::juce_audio_formats
    juce::juce_audio_utils
    juce::juce_core
    juce::juce_events
    juce::juce_graphics
    juce::juce_gui_basics
    juce::juce_gui_extra
    juce::juce_cryptography
    juce::juce_recommended_config_flags
    $<$<NOT:$<PLATFORM_ID:Windows>>:curl>
)
