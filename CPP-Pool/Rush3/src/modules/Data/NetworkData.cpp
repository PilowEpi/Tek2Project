/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** Use.deviceModule
*/

#include <iostream>
#include <sstream>
#include <algorithm>

#include "Networking.hpp"
#include "NetworkData.hpp"

NetworkData::NetworkData()
{
	units["octet"] = 1;
	units["Ko"] = 10e3;
	units["Mo"] = 10e6;
	units["Go"] = 10e9;
	units["To"] = 10e12;
	units["Po"] = 10e15;
	units["Eo"] = 10e18;
	units["Zo"] = 10e21;
	units["Yo"] = 10e24;
}

NetworkData::~NetworkData()
{
}

void NetworkData::update(IMonitorModule *mod)
{
	Networking *Network = (Networking *) mod;
	computed_net = Network->getNetworkingData();
	adaptatorcount = Network->getAdaptatorsNb();

	std::deque<NetData> &allNetwork = computed_net.back();
	for (NetData &data : allNetwork) {
		if (data.tx == 0 && data.rx == 0) {
			if (input[data.device].size() == 0) {
				float *newin = new float[2];
				newin[0] = -1;
				input[data.device].push_front(newin);
				input[data.device].front()[0] = -1;
				input[data.device].front()[1] = -1;
			}
			if (output[data.device].size() == 0) {
				float *newout = new float[2];
				newout[0] = -1;
				output[data.device].push_front(newout);
				output[data.device].front()[0] = -1;
				output[data.device].front()[1] = -1;
			}
			continue;
		}
		float fact = inputMax[data.device] == 0 ? 1.0 : inputMax[data.device];
		std::for_each(input[data.device].begin(), input[data.device].end(), [fact] (float *f) {f[0] = f[0] * fact; });
		float *newinput = new float[2];
		newinput[0] = data.rx * units[data.rx_unity];
		newinput[1] = -1;
		input[data.device].push_front(newinput);
		if (input[data.device].back()[0] == -1 && input[data.device].back()[1] == -1) {
			input[data.device].pop_back();
		}
		inputMax[data.device] = newinput[0] > inputMax[data.device] ? newinput[0] : inputMax[data.device];
		fact = inputMax[data.device] == 0 ? 1.0 : inputMax[data.device];
		std::for_each(input[data.device].begin(), input[data.device].end(), [fact] (float *f) {f[0] = f[0] / fact; });

		fact = outputMax[data.device] == 0 ? 1.0 : outputMax[data.device];
		std::for_each(output[data.device].begin(), output[data.device].end(), [fact] (float *f) {f[0] = f[0] * fact; });
		float *newoutput = new float[2];
		newoutput[0] = data.tx * units[data.tx_unity];
		newoutput[1] = -1;
		output[data.device].push_front(newoutput);
		if (output[data.device].back()[0] == -1 && output[data.device].back()[1] == -1) {
			output[data.device].pop_back();
		}
		outputMax[data.device] = newoutput[0] > outputMax[data.device] ? newoutput[0] : outputMax[data.device];
		fact = outputMax[data.device] == 0 ? 1.0 : outputMax[data.device];
		std::for_each(output[data.device].begin(), output[data.device].end(), [fact] (float *f) {f[0] = f[0] / fact; });
	}
}

std::string NetworkData::data()
{
	std::ostringstream stream("");
	stream << "Core count: " << adaptatorcount << std::endl;
	return stream.str();
}

std::map<std::string, std::deque<float *>> &NetworkData::getOutput()
{
	return output;
}

std::map<std::string, std::deque<float *>> &NetworkData::getInput()
{
	return input;
}