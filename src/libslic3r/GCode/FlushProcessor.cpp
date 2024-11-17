// FlushProcessor.cpp
// OrcaSlicer
//
#include "../GCode.hpp"
#include "FlushProcessor.hpp"
#include <sstream>
#include <iostream>

namespace Slic3r {

FlushProcessor::FlushProcessor(GCode &gcodegen)
    : m_gcodegen(gcodegen),
      m_config(gcodegen.config())
{
}

std::string FlushProcessor::process_layer(std::string &&gcode) {
    std::istringstream stream(gcode);
    std::string line;
    std::ostringstream output;
    bool flush_command = false;
    // Iterate through each line of the layer G-code
    while (std::getline(stream, line)) {
        if(!m_config.flush_to_external_device){ // if flush to external device option is disabled, return early to speed processing up
            output << line << '\n';
        }else{
            // If a flush command is found, ignore all subsequent lines till the flush end command is found
            if (line.find("; FLUSH_START") != std::string::npos)
                flush_command = true;
            if (line.find("; FLUSH_END") != std::string::npos)
                flush_command = false;
            if (!flush_command)
                output << line << '\n';
        }
    }
    return output.str();
}

} // namespace Slic3r
