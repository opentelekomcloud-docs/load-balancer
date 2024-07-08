:original_name: elb_ug_hdg_0006.html

.. _elb_ug_hdg_0006:

Changing a Backend Server Group
===============================

Scenario
--------

This section describes how you can change the default backend server group configured for a listener.

TCP or UDP listeners forward requests to the default backend server groups.

HTTP or HTTPS listeners forward requests based on the priorities of the forwarding policies. If you do not add a forwarding policy, the listener will route the requests to the default backend server group.

Constraints and Limitations
---------------------------

-  The backend server group cannot be changed if redirection is enabled.
-  The backend protocol of the backend server group must match the frontend protocol of the listener. For details, see :ref:`Table 3 <elb_ug_hdg_0001__table89265491950>`.

Procedure
---------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. On the **Load Balancers** page, locate the target load balancer and click its name.

#. On the **Listeners** tab, locate the target listener and click its name.

#. On the **Summary** page, click **Change Backend Server Group** on the right.

#. In the displayed dialog box, click the server group name box.

   Select a backend server group from the drop-down list or create a new group.

   a. Click the name of the backend server group or enter the name in the search box to search for the target group.
   b. Click **Create Backend Server Group** to create a new backend server group. After the backend server group is created, click the refresh icon.

      .. note::

         The backend protocol of the new backend server group must match the frontend protocol of the listener.

#. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001794660553.png
.. |image2| image:: /_static/images/en-us_image_0000001747380852.png
