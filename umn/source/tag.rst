:original_name: elb_ug_bq_0000.html

.. _elb_ug_bq_0000:

Tag
===

Scenarios
---------

If you have a large number of cloud resources, you can assign different tags to the resources to quickly identify them and use these tags to easily manage your resources.

Adding a Tag to a Load Balancer
-------------------------------

You can add a tag to a load balancer in the following method:

-  Add a tag when you create a load balancer.

   For detailed operations, see :ref:`Creating a Dedicated Load Balancer <elb_lb_000006>` and :ref:`Creating a Shared Load Balancer <en-us_topic_0015479967>`.

-  Add a tag to an existing load balancer.

   #. Log in to the management console.
   #. In the upper left corner of the page, click |image1| and select the desired region and project.
   #. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
   #. Locate the load balancer and click its name.
   #. Under **Tags**, click **Add Tag**.
   #. In the **Add Tag** dialog box, enter a tag key and value and click **OK**.

      .. note::

         -  A maximum of 20 tags can be added to a load balancer.
         -  Each tag is a key-value pair, and the tag key is unique.

Adding a Tag to a Listener
--------------------------

You can add tags when you add listeners.

To add a tag to an existing listener, perform the following steps:

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Click |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**, locate the listener, and click its name.
#. Under **Tags**, click **Add Tag**.
#. In the **Add Tag** dialog box, enter a tag key and value and click **OK**.

   .. note::

      -  A maximum of 20 tags can be added to a listener.
      -  Each tag is a key-value pair, and the tag key is unique.

Modifying a Tag
---------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image5| and select the desired region and project.
#. Click |image6| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Tags**, select the tag to be edited, and click **Edit** in the **Operation** column. In the **Edit Tag** dialog box, change the tag value.

   .. note::

      The tag key cannot be changed.

#. Click **OK**.

The operations for modifying a listener tag are not detailed here. Refer to the operations of modifying a load balancer tag.

Deleting a Tag
--------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image7| and select the desired region and project.
#. Click |image8| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Tags**, select the tag to be deleted, and click **Delete** in the **Operation** column.
#. In the displayed dialog box, click **Yes**.

The operations for deleting a listener tag are not detailed here. Refer to the operations of deleting a load balancer tag.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
.. |image3| image:: /_static/images/en-us_image_0000001747739624.png
.. |image4| image:: /_static/images/en-us_image_0000001794660485.png
.. |image5| image:: /_static/images/en-us_image_0000001747739624.png
.. |image6| image:: /_static/images/en-us_image_0000001794660485.png
.. |image7| image:: /_static/images/en-us_image_0000001747739624.png
.. |image8| image:: /_static/images/en-us_image_0000001794660485.png
