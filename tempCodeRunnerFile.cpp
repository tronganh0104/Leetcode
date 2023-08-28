long long output = 0;
    int n = nums.size();
    priority_queue<int> pq (nums.begin(), nums.end());
    while (k > 0) {
        int maxElement = pq.top();
        pq.pop();
        output += maxElement;
        int newElement = (maxElement % 3 == 0) ? (maxElement / 3) : (maxElement / 3 + 1);
        pq.push(newElement);
        k--;
    }       
    return output;