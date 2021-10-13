How Do I Check Traffic Inconsistency?
=====================================

Check for failed requests on the clients, especially when *4xx* status codes are returned. A possible cause is that the requests are rejected by ELB and are not routed to backend servers because ELB considers these requests abnormal.
