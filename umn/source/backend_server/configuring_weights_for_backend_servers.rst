:original_name: elb_ug_hd_0008.html

.. _elb_ug_hd_0008:

Configuring Weights for Backend Servers
=======================================

Each backend server can be given a numeral value from 0 to 100 to indicate the proportion of requests to receive. Requests are not routed to the backend server whose weight is 0, even if the backend server is considered healthy. You can set a weight for each backend server when you select one of the following algorithms:

-  **Weighted round robin**

   Requests are not routed to a backend server if its weight is set to 0.

   If none of the servers have a weight of 0, the load balancer routes requests to backend servers based on their weights. Backend servers with higher weights receive proportionately more requests.

   If two backend servers have the same weights, they receive the same number of requests.

-  **Weighted least connections**

   Requests are not routed to a backend server if its weight is set to 0.

   If none of the servers have a weight of 0, the load balancer calculates the load of each backend server using the formula (Overhead = Number of current connections/Backend server weight) and routes requests to the backend server with the smallest overhead.

-  **Source IP hash**

   Requests are not routed to a backend server if its weight is set to 0.

   Weights do not take effect even if they are not 0, and requests from the same IP address are routed to the same backend server.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Backend Server Groups**, locate the backend server group and then the server, and click |image3| in the **Weight** column to set the server weight.
#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
.. |image3| image:: /_static/images/en-us_image_0000001747740064.png
