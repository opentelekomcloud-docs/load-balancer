:original_name: elb_ug_hd_0004.html

.. _elb_ug_hd_0004:

Enabling Removal Protection for a Backend Server Group
======================================================

Scenarios
---------

Dedicated load balancers allow you to enable the removal protection option for a backend server group to prevent the servers in it from being removed by accident.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. On the **Load Balancers** page, locate the load balancer and click its name.
#. On the **Listeners** tab, locate the target listener. In the **Default Backend Server Group** column, click **View/Add Backend Server**.
#. Click the **Summary** tab and enable **Removal Protection**.

.. note::

   Disable **Removal Protection** if you want to delete a backend server group or remove a cloud server or an IP address from the backend server group.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
