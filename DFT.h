#ifndef DFT_H
#define DFT_H

#include <vector>
#include "ThreadHelpers.h"

class DFTModule
{
	std::shared_ptr<OneDirectionDataBuffer<DataArray<double>>> in_buffer;
	std::shared_ptr<OneDirectionDataBuffer<DataArray<double>>> out_buffer;
public:
	DFTModule(
		const std::shared_ptr<OneDirectionDataBuffer<DataArray<double>>> in_buffer,
		const std::shared_ptr<OneDirectionDataBuffer<DataArray<double>>> out_buffer
	);

	void execute_loop();
};

#endif // DFT_H 