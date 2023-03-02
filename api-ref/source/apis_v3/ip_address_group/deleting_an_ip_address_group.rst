:original_name: DeleteIpGroup.html

.. _DeleteIpGroup:

Deleting an IP Address Group
============================

Function
--------

This API is used to delete an IP address group.This function is not supported in **eu-nl** region. Please do not use it.

URI
---

DELETE /v3/{project_id}/elb/ipgroups/{ipgroup_id}

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================================
   project_id Yes       String Specifies the project ID.
   ipgroup_id Yes       String Specifies the ID of the IP address group.
   ========== ========= ====== =========================================

Request Parameters
------------------

.. table:: **Table 2** Request header parameters

   +--------------+-----------+--------+--------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                      |
   +==============+===========+========+==================================================+
   | X-Auth-Token | Yes       | String | Specifies the token used for IAM authentication. |
   +--------------+-----------+--------+--------------------------------------------------+

Response Parameters
-------------------

None

Example Requests
----------------

Deleting an IP address group

.. code-block:: text

   DELETE https://{ELB_Endpoint}/v3/45977fa2dbd7482098dd68d0d8970117/elb/ipgroups/8722e0e0-9cc9-4490-9660-8c9a5732fbb0

Example Responses
-----------------

None

Status Codes
------------

=========== ===================
Status Code Description
=========== ===================
204         Successful request.
=========== ===================

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.
