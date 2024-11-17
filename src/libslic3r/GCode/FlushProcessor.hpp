// FlushProcessor.hpp
// OrcaSlicer


#ifndef FLUSHPROCESSOR_H
#define FLUSHPROCESSOR_H

#include <string>
#include <sstream>
#include <regex>

namespace Slic3r {

// Forward declaration of GCode class
class GCode;


class FlushProcessor {
public:
    FlushProcessor(GCode &gcodegen);
    std::string process_layer(std::string &&gcode);

private:
    GCode &m_gcodegen; ///< Reference to the GCode object.
    const PrintConfig &m_config; ///< Reference to the print configuration.
};

} // namespace Slic3r

#endif // FLUSHPROCESSOR_H
