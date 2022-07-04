struct Elem {
	int top;
	int min;
};

class MinStack {
private:
	vector<Elem> _stk;
public:
	/** initialize your data structure here. */
	MinStack() {
		//nothing to initialise
	}

	void push(int val) {
		if (_stk.empty()) {
			//_stk.insert(_stk.begin(), { val, val });
			_stk.push_back({ val, val });
		}
		else {
			//_stk.insert(_stk.begin(), { val, min(val, _stk.front().min) });
			_stk.push_back({ val, min(val, _stk.back().min) });
		}
	}

	void pop() {
		//_stk.erase(_stk.begin());
		_stk.pop_back();
	}

	int top() {
		//return _stk.front().top;
		return _stk.back().top;
	}

	int getMin() {
		//return _stk.front().min;
		return _stk.back().min;
	}
};