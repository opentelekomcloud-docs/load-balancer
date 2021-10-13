Deleting a Load Balancer
========================

Scenarios
---------

You can delete a load balancer if you do not need it any longer.

|image1|

A deleted load balancer cannot be recovered.

After a public network load balancer is deleted, its EIP will not be released and can be used by other resources.

Prerequisites
-------------

You have removed backend servers from the associated backend server groups, deleted the associated backend server groups, and deleted the listeners added to the load balancer.

.. _deleting-a-load-balancer-1:

Deleting a Load Balancer
------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image2| and select the desired region and project.
#. Hover on |image3| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click **Delete** in the **Operation** column.
#. Click **Yes**.

.. |image1| image:: /images/caution_3.0-en-us.png
.. |image2| image:: /images/en-us_image_0241356603.png

.. |image3| image:: /images/en-us_image_0000001120894978.png

