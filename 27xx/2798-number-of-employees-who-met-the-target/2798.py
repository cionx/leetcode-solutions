""" 2798. Number of Employees Who Met the Target """


class Solution:
    def numberOfEmployeesWhoMetTarget(self, hours: list[int], target: int) -> int:
        return len([time for time in hours if time >= target])
