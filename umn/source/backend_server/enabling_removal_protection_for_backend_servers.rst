:original_name: elb_ug_hd_0004.html

.. _elb_ug_hd_0004:

Enabling Removal Protection for Backend Servers
===============================================

Scenarios
---------

Dedicated load balancers allow you to enable removal protection for associated backend servers to prevent them from being removed by accident.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. On the **Load Balancers** page, locate the load balancer and click its name.
#. Click **Backend Server Groups**, locate the backend server group, and click its name.
#. In the **Basic Information** area on the right, enable **Removal Protection**.

.. note::

   Disable **Removal Protection** if you want to delete a backend server group or remove a cloud server or an IP address from the backend server group.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001417088430.png
