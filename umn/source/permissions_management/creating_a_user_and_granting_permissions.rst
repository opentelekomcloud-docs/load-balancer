:original_name: en-us_topic_0162009774.html

.. _en-us_topic_0162009774:

Creating a User and Granting Permissions
========================================

Use `IAM <https://docs.otc.t-systems.com/usermanual/iam/iam_01_0026.html>`__ to implement fine-grained permissions control over your ELB resources. With IAM, you can:

-  Create IAM users for employees based on your enterprise's organizational structure. Each IAM user will have their own security credentials for accessing ELB resources.
-  Grant only the permissions required for users to perform a specific task.
-  Entrust another account or cloud service to perform efficient O&M on your ELB resources.

Skip this section if your account does not need individual IAM users.

This following describes the procedure for granting permissions.

Prerequisites
-------------

You have learned about ELB policies and can select the appropriate policies based on service requirements. Learn about :ref:`permissions <en-us_topic_0171274900>` supported by ELB. For the permissions of other services, see `Permission Description <https://docs.otc.t-systems.com/en-us/permissions/index.html>`__.

Process Flow
------------


.. figure:: /_static/images/en-us_image_0171320637.jpg
   :alt: **Figure 1** Process for granting ELB permissions

   **Figure 1** Process for granting ELB permissions

#. .. _en-us_topic_0162009774__li8447183891715:

   `Create a user group and assign permissions <https://docs.otc.t-systems.com/en-us/usermanual/iam/iam_01_0030.html>`__.

   Create a user group on the IAM console and assign the **ELB ReadOnlyAccess** policy to the group.

#. `Create a user and add it to a user group <https://docs.otc.t-systems.com/usermanual/iam/iam_01_0031.html>`__.

   Create a user on the IAM console and add the user to the group created in :ref:`1 <en-us_topic_0162009774__li8447183891715>`.

#. `Log in <https://docs.otc.t-systems.com/usermanual/iam/iam_01_0032.html>`__ and verify permissions.

   Log in to the ELB console by using the created user, and verify that the user only has read permissions for ELB.

   -  Choose **Service List** > **Elastic Load Balance**. Then click **Create Elastic Load Balancer** on the ELB console. If you cannot create a load balancer, the **ELB ReadOnlyAccessELB Viewer** policy has taken effect.
   -  Choose any other service in **Service List**. If a message appears indicating that you have insufficient permissions to access the service, the **ELB ReadOnlyAccess** policy has already taken effect.
