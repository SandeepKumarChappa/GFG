//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class AutoCompleteSystem {
private:
    unordered_map<string, int> freqMap; // Map to store sentence frequencies
    string currentQuery;               // To keep track of the ongoing query

public:
    // Constructor to initialize the system with historical data
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < sentences.size(); ++i) {
            freqMap[sentences[i]] += times[i];
        }
        currentQuery = ""; // Initialize current query as empty
    }

    // Function to return top 3 suggestions or save the query
    vector<string> input(char c) {
        if (c == '#') {
            // Save the completed query and reset currentQuery
            freqMap[currentQuery]++;
            currentQuery = "";
            return {};
        }

        // Append character to the current query
        currentQuery += c;

        // Find all sentences with the prefix of currentQuery
        vector<pair<int, string>> candidates;
        for (const auto& entry : freqMap) {
            if (entry.first.find(currentQuery) == 0) { // Check if it matches prefix
                candidates.push_back({-entry.second, entry.first}); // Use negative frequency for sorting
            }
        }

        // Sort candidates by frequency (descending) and lexicographically (ascending)
        sort(candidates.begin(), candidates.end());

        // Prepare the result with at most 3 entries
        vector<string> result;
        for (int i = 0; i < min(3, (int)candidates.size()); ++i) {
            result.push_back(candidates[i].second);
        }
        return result;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        vector<string> sentences(n);
        vector<int> times(n);
        for (int i = 0; i < n; ++i) {

            getline(cin, sentences[i]);
            cin >> times[i];
            cin.ignore();
        }
        AutoCompleteSystem *obj = new AutoCompleteSystem(sentences, times);
        int q;
        cin >> q;
        cin.ignore();

        for (int i = 0; i < q; ++i) {
            string query;
            getline(cin, query);
            string qq = "";
            for (auto &x : query) {
                qq += x;
                vector<string> suggestions = obj->input(x);
                if (x == '#')
                    continue;
                cout << "Typed : \"" << qq << "\" , Suggestions: \n";
                for (auto &y : suggestions) {
                    cout << y << "\n";
                }
            }
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends