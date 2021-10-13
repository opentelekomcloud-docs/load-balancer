Why Is the Interval at Which Backend Servers Receive Health Check Packets Different from the Configured Health Check Interval?
==============================================================================================================================

Each LVS node and Nginx node in the ELB system detect backend servers at the health check interval that you have specified for the backend server group.

During this period, backend servers receive multiple detection packets from LVS and Nginx nodes. This makes it seem that backend servers receive these packets at intervals shorter than the specified health check interval.
