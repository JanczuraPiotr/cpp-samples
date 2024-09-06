#ifndef CONTROLLED_CONSTRUCTION
#define CONTROLLED_CONSTRUCTION

#include <memory>
#include <string>
#include <stdexcept>

class ControlledConstruction {
public:
    using Ptr = std::shared_ptr<ControlledConstruction>;
    enum class Valid {
        OK,
        TO_SHORT,
        TO_LONG
    };
    static Valid validate(const std::string &name) {
        if (auto size = name.size(); size < 3) {
            return Valid::TO_SHORT;
        } else if( size > 10) {
            return Valid::TO_LONG;
        } else {
            return Valid::OK;
        }
    }

    static Ptr create(const std::string &name) {
        switch (validate(name)) {
            case Valid::TO_LONG:
                throw std::runtime_error("Napis jest za długi.");
            case Valid::TO_SHORT:
                throw std::runtime_error("Napis jest za krótki.");
            default:
              return Ptr{new ControlledConstruction{name}};
        }
    }

    virtual ~ControlledConstruction() = default;

    std::string name() const {
        return _name;
    }

private:
    explicit ControlledConstruction(std::string name)
        : _name(std::move(name)) { }

protected:

private:
    std::string _name;
};


#endif