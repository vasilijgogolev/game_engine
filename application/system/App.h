#pragma once

namespace Application {
	class App {
	public:
		App() = default;
		~App() = default;

		bool initialize();
		void run();

	private:
		bool inited = false;
	};
}