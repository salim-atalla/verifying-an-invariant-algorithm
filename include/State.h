#ifndef STATE_H
#define STATE_H

#include <string>
#include <unordered_map>
#include <functional>

// Represents a state in the transition system
class State {
public:
    // Constructor
    State(const std::string& id, const std::unordered_map<std::string, bool>& propositions = {});

    // Getter for the state ID
    std::string getId() const;

    // Adds or updates a proposition value in the state
    void setPropositionValue(const std::string& name, bool value);

    // Retrieves the value of a proposition by name
    bool getPropositionValue(const std::string& name) const;

    // Overloading the == operator to compare two states
    bool operator==(const State& other) const {
        return id == other.id && propositions == other.propositions;
    }

    // Hash function
    struct Hash {
        std::size_t operator()(const State& state) const {
            std::size_t hashValue = std::hash<std::string>()(state.id);
            for (const auto& pair : state.propositions) {
                hashValue ^= std::hash<std::string>()(pair.first) ^ std::hash<bool>()(pair.second);
            }
            return hashValue;
        }
    };

private:
    std::string id; // Unique identifier for the state
    std::unordered_map<std::string, bool> propositions;  // Map of proposition names to values
};

#endif // STATE_H
