#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data *data = new Data();
	data->value = strdup("I shall remain untouched");

	uintptr_t serializedData = Serializer::serialize(data);
	Data *deserializedData = Serializer::deserialize(serializedData);

	std::cout << deserializedData->value << '\n';
	delete deserializedData->value;
	delete deserializedData;
}
