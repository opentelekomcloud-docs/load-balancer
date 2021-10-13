Configuring Weights for Backend Servers
=======================================

Each backend server can be given a numeral value from 0 to 100 to indicate the proportion of requests to receive. Requests will not be routed to the backend server whose weight is 0, even if the backend server is considered healthy. You can set a weight for each backend server when you select one of the following algorithms:

-  Weighted round robin: If none of the servers have a weight of 0, the load balancer routes requests to these servers using the round robin algorithm based on their weights. If two backend servers have the same weights, they receive the same number of requests.
-  Weighted least connections: If none of the servers have a weight of 0, the load balancer calculates the load of each backend server using the formula: Overhead = Number of current connections/Server weight. The load balancer routes requests to the backend server with the lowest overhead in each request distribution.
-  Source IP hash: Requests will not be routed to backend servers if their weights are set to 0. Server weights will not take effect if they are not 0, and requests from the same IP address will be routed to the same backend server.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Backend Server Groups**, locate the backend server group and then the server, and click the number in the **Weight** column to set the server weight.
#. Click **OK**.

.. |image1| image:: /images/en-us_image_0241356603.png

.. |image2| image:: /images/en-us_image_0000001120894978.png

