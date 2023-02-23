:original_name: elb_ug_hc_0005.html

.. _elb_ug_hc_0005:

Changing the Health Check Protocol
==================================

Scenarios
---------

You can change the health check protocol as required. After the protocol is changed, the load balancer uses the new protocol to detect the health of backend servers, and it continues to route traffic to the backend servers after they are detected healthy.

During this period, the load balancer may return the HTTP 503 error code to the clients.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Backend Server Groups**, locate the backend server group, and click its name.
#. Click **More** in the **Operation** column.
#. Select **Configure Health Check** from the drop-down list.
#. In the **Basic Information** area, click **Configure** next to **Health Check**.
#. Change the health check protocol.
#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001417088430.png
