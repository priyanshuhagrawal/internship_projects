#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Candidate
{
    std::string name;
    std::string party;
    int votes;

    Candidate(const std::string &n, const std::string &p) : name(n), party(p), votes(0) {}
};

class Election
{
private:
    std::vector<Candidate> candidates;

public:
    void addCandidate(const std::string &name, const std::string &party)
    {
        candidates.push_back(Candidate(name, party));
    }

    void displayCandidates()
    {
        std::cout << "List of Candidates:\n";
        for (size_t i = 0; i < candidates.size(); ++i)
        {
            std::cout << i + 1 << ". " << candidates[i].name << " (" << candidates[i].party << ")\n";
        }
    }

    int castVote()
    {
        int choice;
        std::cout << "Select a candidate to vote for (enter candidate number): ";
        std::cin >> choice;

        if (choice < 1 || choice > static_cast<int>(candidates.size()))
        {
            std::cout << "Invalid candidate number.\n";
            return -1;
        }

        candidates[choice - 1].votes++;
        std::cout << "Vote cast for " << candidates[choice - 1].name << " (" << candidates[choice - 1].party << ")\n";
        return choice;
    }

    void displayResults()
    {
        std::cout << "\nElection Results:\n";
        int maxVotes = 0;
        int winnerIndex = -1;

        for (size_t i = 0; i < candidates.size(); ++i)
        {
            std::cout << candidates[i].name << " (" << candidates[i].party << "): " << candidates[i].votes << " votes\n";

            if (candidates[i].votes > maxVotes)
            {
                maxVotes = candidates[i].votes;
                winnerIndex = static_cast<int>(i);
            }
        }

        if (winnerIndex != -1)
        {
            std::cout << "\nWinner: " << candidates[winnerIndex].name << " (" << candidates[winnerIndex].party << ")\n";
        }
        else
        {
            std::cout << "\nNo winner. Election tied.\n";
        }
    }
};

int main()
{
    Election election;

    // Adding sample candidates
    election.addCandidate("Modi", "BJP");
    election.addCandidate("Rahul", "Congress");
    election.addCandidate("Kejriwal", "AAP");

    int numVotes;
    std::cout << "Enter the number of votes: ";
    std::cin >> numVotes;

    for (int i = 0; i < numVotes; ++i)
    {
        election.displayCandidates();
        int voteResult = election.castVote();

        while (voteResult == -1)
        {
            election.displayCandidates();
            voteResult = election.castVote();
        }
    }

    election.displayResults();

    return 0;
}
