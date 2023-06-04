#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	int counter[100001];     /* amount[i] is how often i has been added */
	int frequencies[100001]; /* freqency[f] is how many inputs */
} FrequencyTracker;          /* of amount f there are          */

FrequencyTracker *frequencyTrackerCreate(void);
void frequencyTrackerAdd(FrequencyTracker *tracker, int value);
void frequencyTrackerDeleteOne(FrequencyTracker *tracker, int value);
bool frequencyTrackerHasFrequency(FrequencyTracker *tracker, int freq);
void frequencyTrackerFree(FrequencyTracker *tracker);

FrequencyTracker *frequencyTrackerCreate(void)
{
	FrequencyTracker *tracker = malloc(sizeof(FrequencyTracker));
	*tracker = (FrequencyTracker){.counter = {0}, .frequencies = {0}};

	return tracker;
}

void frequencyTrackerAdd(FrequencyTracker *tracker, int value)
{
	int old_freq = tracker->counter[value]++;
	if (old_freq >= 1)
		tracker->frequencies[old_freq]--;
	tracker->frequencies[old_freq + 1]++;
}

void frequencyTrackerDeleteOne(FrequencyTracker *tracker, int value)
{
	int old_freq = tracker->counter[value];
	if (old_freq >= 1) {
		tracker->counter[value]--;
		tracker->frequencies[old_freq]--;
		if (old_freq >= 2)
			tracker->frequencies[old_freq - 1]++;
	}
}

bool frequencyTrackerHasFrequency(FrequencyTracker *tracker, int freq)
{
	return tracker->frequencies[freq] > 0;
}

void frequencyTrackerFree(FrequencyTracker *tracker)
{
	free(tracker);
}
